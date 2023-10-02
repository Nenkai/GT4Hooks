#pragma once

typedef enum
{
  FileError_OK = 0x0,
  FileError_CANCEL = 0x1,
  FileError_NOTSUPPORT = 0x2,
  FileError_NOMEMORY = 0x3,
  FileError_NODEVICE = 0x4,
  FileError_IO = 0x5,
  FileError_DEVICEFULL = 0x6,
  FileError_READONLY = 0x7,
  FileError_NOTPERMITTED = 0x8,
  FileError_NOTFOUND = 0x9,
  FileError_ILLEGAL = 0xA,
} FileError;

typedef enum CameraOnboardMount
{
    CameraOnboardMount_DEFAULT = 0, /*!< 0 */
    CameraOnboardMount_DRIVER = 0, /*!< 0 */
    CameraOnboardMount_CHASE = 1, /*!< 1 */
    CameraOnboardMount_MIRROR_L = 3, /*!< 3 */
    CameraOnboardMount_MIRROR_R = 4, /*!< 4 */
    CameraOnboardMount_NOSE = 5, /*!< 5 */
    CameraOnboardMount_BONNET = 6, /*!< 6 */
    CameraOnboardMount_ROOF = 7, /*!< 7 */
    CameraOnboardMount_BACK = 8, /*!< 8 */
    CameraOnboardMount_TAIL = 9, /*!< 9 */
    CameraOnboardMount_SIDE_L = 10, /*!< 10 */
    CameraOnboardMount_SIDE_R = 11, /*!< 11 */
    CameraOnboardMount_FENDER_L = 12, /*!< 12 */
    CameraOnboardMount_FENDER_R = 13, /*!< 13 */
    CameraOnboardMount_WHEEL_FL = 14, /*!< 14 */
    CameraOnboardMount_WHEEL_FR = 15, /*!< 15 */
    CameraOnboardMount_WHEEL_RL = 16, /*!< 16 */
    CameraOnboardMount_WHEEL_RR = 17, /*!< 17 */
    CameraOnboardMount_OPTION_1 = 18, /*!< 18 */
    CameraOnboardMount_OPTION_2 = 19, /*!< 19 */
    CameraOnboardMount_METER = 20, /*!< 20 */
    CameraOnboardMount_CHAR1 = 21, /*!< 21 */
    CameraOnboardMount_CHAR2 = 22, /*!< 22 */
    CameraOnboardMount_CHAR3 = 23, /*!< 23 */
    CameraOnboardMount_CHAR4 = 24, /*!< 24 */
    CameraOnboardMount_DRIVER2 = 25, /*!< 25 */
} CameraOnboardMount;