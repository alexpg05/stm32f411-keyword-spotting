# STM32F411 Keyword Spotting

## Project Description

This project demonstrates keyword spotting on the NUCLEO-F411RE board using STM32's audio package and TinyKW library.
The NUCLEO board is connected to the IMP34DT05 digital microphone located on a X-NUCLEO-IKS02A1 expansion board.
The MCU accesses the PDM data via the SPI/I2S protocol and DMA saves it to a buffer in SRAM. 
Once the half-buffer interrupt triggers, the PDM data is converted to PCM using STM32's PDM2PCM library.
PCM data is then processed to detect keywords using TinyKW library.

## Demo

https://github.com/user-attachments/assets/4fa679fd-4fd8-4727-9687-660d7c79d8c7

## Hardware setup

![](docs/hardware.jpeg)

- PA7 -> R 220 -> cathode Green LED -> +3V3
- PB6 -> R 220 -> cathode Red LED -> +3V3
- PC7 -> R 220 -> cathode Yellow LED -> +3V3

In this setup, setting an output pin HIGH turns the LED off, and setting it LOW turns the LED on.

## Software setup

1. Generate the code:
    - Open STM32CubeMX and load the project stm32f411-voice-interaction.ioc.
    - Click on `Generate Code` to generate the code.
    - Verify that the folders Drivers, Middlewares (with PDM library in it) and PDM2PCM were created at the root of this directory.
2. Build and run:
    - Open STM32CubeIDE and import this directory as a project. Try building the project and running it with the nucleo board connected.

## Using another language

TinyKW is included in `Libs/tinykw` for all supported languages, and the English version is used by default. To use a different language, the path of the library needs to be modified. This can be done as follows;
- In STM32CubeIDE, Select the project, then `File` > `Properties` > `C/C++ Build` > `Settings` > `MCU/MPU GCC Linker` > `Include Path`
- Modify the path `../Libs/tinykw/lib/en` into `../Libs/tinykw/lib/<language>`. Possible values for `<language>` are `en`, `fr`, `de`, `es`, `it`, `pt`, `zh` and `ja`.

## Using other keywords

To use other keywords, their byte representations need to be retrieved from the [TinyKW Console](https://voyelle.io/tinykw/encoder) and pasted into [keywords_encodings.c](Core/Src/keywords_encodings.c). Byte representation of keywords must match the language used. If necessary, the detection threshold can be adapted using the preprocessor macro `DETECTION_THRESHOLD` in [main.c](Core/Src/main.c). Please refer to TinyKW documentation for more details.

## License

The code in this repository is licensed under MIT. TinyKW is distributed as a prebuilt library under the Apache 2.0 license (see `Libs/tinykw/LICENSE`).
STM32CubeMX's generated code and STM32's PDM2PCM library are not bundled and remain subject to their own license.
