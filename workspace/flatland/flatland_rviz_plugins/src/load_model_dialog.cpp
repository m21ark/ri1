/*
 *  ______                   __  __              __
 * /\  _  \           __    /\ \/\ \            /\ \__
 * \ \ \L\ \  __  __ /\_\   \_\ \ \ \____    ___\ \ ,_\   ____
 *  \ \  __ \/\ \/\ \\/\ \  /'_` \ \ '__`\  / __`\ \ \/  /',__\
 *   \ \ \/\ \ \ \_/ |\ \ \/\ \L\ \ \ \L\ \/\ \L\ \ \ \_/\__, `\
 *    \ \_\ \_\ \___/  \ \_\ \___,_\ \_,__/\ \____/\ \__\/\____/
 *     \/_/\/_/\/__/    \/_/\/__,_ /\/___/  \/___/  \/__/\/___/
 * @copyright Copyright 2017 Avidbots Corp.
 * @name   load_model_dialog.cpp
 * @brief  Spawn dialog
 * @author Joseph Duchesne
 * @author Mike Brousseau
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2017, Avidbots Corp.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Avidbots Corp. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#include "flatland_rviz_plugins/load_model_dialog.hpp"

#include <string>

#include <OgreVector3.h>

#include <QCheckBox>
#include <QCursor>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <boost/filesystem.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rviz_common/properties/float_property.hpp>
#include <rviz_common/tool_manager.hpp>
#include <rviz_common/viewport_mouse_event.hpp>
#include <rviz_common/visualization_manager.hpp>


namespace flatland_rviz_plugins
{

QString LoadModelDialog::path_to_model_file;
int LoadModelDialog::count;
bool LoadModelDialog::numbering;

LoadModelDialog::LoadModelDialog(
  QWidget * parent, rviz_common::DisplayContext * context, SpawnModelTool * tool)
: QDialog(parent), context_(context), tool_(tool)
{
  RCLCPP_INFO_STREAM(rclcpp::get_logger("ModelDialog"), "ModelDialog::ModelDialog");
  auto * v_layout = new QVBoxLayout;
  setLayout(v_layout);

  // we are injecting horizontal layouts into the master vertical layout
  auto * h0_layout = new QHBoxLayout;
  auto * h1_layout = new QHBoxLayout;
  auto * h2_layout = new QHBoxLayout;
  auto * h3_layout = new QHBoxLayout;

  // create widgets
  auto * pathButton = new QPushButton("choose file");
  p_label = new QLabel;
  n_checkbox = new QCheckBox;
  n_edit = new QLineEdit;
  auto * okButton = new QPushButton("ok");
  auto * cancelButton = new QPushButton("cancel");

  // set focus policy, otherwise cr in textfield triggers all the slots
  pathButton->setFocusPolicy(Qt::NoFocus);
  p_label->setFocusPolicy(Qt::NoFocus);
  n_checkbox->setFocusPolicy(Qt::NoFocus);
  n_edit->setFocusPolicy(Qt::ClickFocus);  // only name gets focus
  okButton->setFocusPolicy(Qt::NoFocus);
  cancelButton->setFocusPolicy(Qt::NoFocus);

  connect(pathButton, &QAbstractButton::clicked, this, &LoadModelDialog::on_PathButtonClicked);
  connect(okButton, &QAbstractButton::clicked, this, &LoadModelDialog::OkButtonClicked);
  connect(cancelButton, &QAbstractButton::clicked, this, &LoadModelDialog::CancelButtonClicked);
  connect(n_checkbox, &QAbstractButton::clicked, this, &LoadModelDialog::NumberCheckBoxChanged);

  // path button
  h0_layout->addWidget(pathButton);

  // path label
  p_label->setText(path_to_model_file);
  h1_layout->addWidget(new QLabel("path:"));
  h1_layout->addWidget(p_label);

  //
  h2_layout->addWidget(new QLabel("number:"));
  h2_layout->addWidget(n_checkbox);
  n_checkbox->setChecked(numbering);
  h2_layout->addWidget(new QLabel("name:"));
  h2_layout->addWidget(n_edit);

  // set the default name to the filename parsed using boost
  AddNumberAndUpdateName();

  // ok button
  h3_layout->addWidget(okButton);

  // cancel button
  h3_layout->addWidget(cancelButton);

  // add the horizontal layouts to the vertical layout
  v_layout->addLayout(h0_layout);
  v_layout->addLayout(h1_layout);
  v_layout->addLayout(h2_layout);
  v_layout->addLayout(h3_layout);

  // set the top level layout
  setLayout(v_layout);

  // delete the Dialog if the user clicks on the x to close window
  this->setAttribute(Qt::WA_DeleteOnClose, true);
}

void LoadModelDialog::CancelButtonClicked()
{
  RCLCPP_INFO_STREAM(rclcpp::get_logger("ModelDialog"), "LoadModelDialog::CancelButtonClicked");

  auto tool_man = context_->getToolManager();
  auto dflt_tool = tool_man->getDefaultTool();
  tool_man->setCurrentTool(dflt_tool);

  this->close();
}

void LoadModelDialog::OkButtonClicked()
{
  RCLCPP_INFO_STREAM(rclcpp::get_logger("ModelDialog"), "LoadModelDialog::OkButtonClicked");

  QString name = n_edit->displayText();

  tool_->SaveName(name);
  tool_->SavePath(path_to_model_file);
  tool_->BeginPlacement();

  this->close();
}

void LoadModelDialog::AddNumberAndUpdateName()
{
  std::string bsfn = boost::filesystem::basename(path_to_model_file.toStdString());
  QString name = QString::fromStdString(bsfn);

  if (numbering) {
    name = name.append(QString::number(count++));
  }

  // update the name text field
  n_edit->setText(name);
}

void LoadModelDialog::on_PathButtonClicked()
{
  RCLCPP_INFO_STREAM(rclcpp::get_logger("ModelDialog"), "LoadModelDialog::on_PathButtonClicked");
  path_to_model_file = ChooseFile();

  AddNumberAndUpdateName();
  p_label->setText(path_to_model_file);
  n_edit->setFocus();
}

void LoadModelDialog::NumberCheckBoxChanged(bool i)
{
  RCLCPP_INFO_STREAM(rclcpp::get_logger("ModelDialog"), "NumberCheckBoxChanged " << i);
  numbering = !numbering;
  AddNumberAndUpdateName();
}

QString LoadModelDialog::ChooseFile()
{
  QString fileName = QFileDialog::getOpenFileName(NULL, tr("Open model file"), "", "");
  if (fileName.isEmpty()) {
    return fileName;
  } else {
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
      QMessageBox::information(NULL, tr("Unable to open file"), file.errorString());
      return fileName;
    }
    file.close();

    return fileName;
  }
}

}  // namespace flatland_rviz_plugins
