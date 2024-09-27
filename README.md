# STM32-Hotspot/ULP & battery less demo with STM32U0

This project is partial project of the **battery less demo with STM32U0**.

It contains the two main sub-projects: 
- The full project of the **1_Data-Logger-and-Transmission-Module**, developped with **IAR 9.30**.
- Licence free parts of the **2_Receiver-and-Display-Module** project, developped with **IAR 8.50**.

It also contains one additional project:
- The full project of the TouchGFX Designer display (**OTHER_Display-TouchGFX-project**), from which the display part of the **2_Receiver-and-Display-Module** is based. It was developped with **TouGFX 4.24.0 Designer**. 

For more information, refer to the related [STM32 wiki article](https://wiki.st.com/stm32mcu/wiki/How_to_develop_ultra-low-power_and_battery_less_demo_with_STM32U0_MCUs).

## Hardware used

**1_Data-Logger-and-Transmission-Module**:

| Name             | Board   | Documentation                                             |
| ---------------- | ------- | --------------------------------------------------------- |
| STM32U083C-DK    | MB1933B | https://www.st.com/en/evaluation-tools/stm32u083c-dk.html | 
| X-Nucleo-S2828A2 | MB1642D | https://www.st.com/en/ecosystems/x-nucleo-s2868a2.html    |


**2_Receiver-and-Display-Module**

| Name             | Board    | Documentation                                                |
| ---------------- | -------- | ------------------------------------------------------------ |
| Nucleo-U083RC    | MB1932B  | https://www.st.com/en/evaluation-tools/nucleo-u083rc.html    |
| X-Nucleo-GFX01M2 | XS2868V2 | https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m2.html |
| X-Nucleo-S2828A2 | MB1642D  | https://www.st.com/en/ecosystems/x-nucleo-s2868a2.html       | 