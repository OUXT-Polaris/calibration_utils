// Copyright (c) 2019 OUXT Polaris
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CALIBRATION_UTILS__CALIBRATION_PANEL_HPP_
#define CALIBRATION_UTILS__CALIBRATION_PANEL_HPP_

#ifndef Q_MOC_RUN
    #include <rclcpp/rclcpp.hpp>
    #include <rviz_common/panel.hpp>
    #include <string>
#endif

namespace calibration_utils
{
class CalibrationPanel : public rviz_common::Panel
{
  Q_OBJECT

public:
  explicit CalibrationPanel(QWidget * parent = 0);
  ~CalibrationPanel();

  virtual void load(const rviz_common::Config & config);
  virtual void save(rviz_common::Config config) const;
};
}  // namespace calibration_utils

#endif  // CALIBRATION_UTILS__CALIBRATION_PANEL_HPP_
