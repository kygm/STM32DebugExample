# STM32F103CBT6 PlatformIO Debug Instructions

## KYGM 12/27/24

**Introduction**

This document describes how to debug on the STM32F103CBT6 (herinafter called STM32)
using PlatformIO in Visual Studio Code

**Useful References**

1. https://developer.mamezou-tech.com/en/blogs/2024/01/29/stm32-debug-by-st-link/

**Instructions**

1. Ensure that the PlatformIO extension is installed
2. Open the platformio.ini file and paste the following (change leperry with the appropriate
    username if it changes):

```
[env:genericSTM32F103C8]
```
```
platform_packages =
; use GCC AVR 5.0+
platformio/tool-openocd@^3.1200.
```
```
platform = ststm
board = genericSTM32F103C
framework = arduino
upload_flags = -c set CPUTAPID 0x2ba
```
```
debug_tool = stlink
debug_init_break = tbreak setup
build_type = debug
debug_server =
/usr/bin/openocd
-s /home/leperry/.platformio/packages/tool-openocd/scripts
-f interface/stlink.cfg
-c "transport select hla_swd"
-c "set CPUTAPID 0x2ba01477"
-f target/stm32f1x.cfg
-c "reset_config none"
```
3. Click the debug button to start debugging, it is normal to hit the setup function if no
    breakpoint is set there


