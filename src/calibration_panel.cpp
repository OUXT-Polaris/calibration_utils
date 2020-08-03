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

#include <calibration_utils/calibration_panel.hpp>

namespace calibration_utils
{
CalibrationPanel::CalibrationPanel(QWidget* parent) : rviz_common::Panel(parent)
{
}

CalibrationPanel::~CalibrationPanel()
{
}

void CalibrationPanel::save( rviz_common::Config config ) const {
  rviz_common::Panel::save( config );
}

void CalibrationPanel::load( const rviz_common::Config& config ) {
  rviz_common::Panel::load( config );
}
}  // namespace calibration_utils
