# 8051 & LPC2148 Microcontroller Practicals

A collection of Microcontroller and Applications (MCA) practical programs using the **8051 Microcontroller** and **ARM7 LPC2148**.

This repository contains C programs, implementation notes, and compilation instructions for microcontroller interfacing experiments.

## Repository Structure

```text
8051-LPC2148-Microcontroller-Practicals/
│
├── 8051/
│   ├── 01_LED_Interfacing.c
│   ├── 02_Stepper_Motor_Interfacing.c
│   └── 03_Relay_and_Buzzer_Interfacing.c
│
├── LPC2148/
│   ├── 04_GLCD_Interfacing.c
│   ├── 05_4x4_Keypad_Interfacing.c
│   ├── 06_GPS_Interfacing.c
│   ├── 07_On_Chip_RTC.c
│   └── 08_SD_Card_SPI_Interfacing.c
│
└── README.md
```

## Practical List

### 8051 Microcontroller

| No. | Practical | Description |
|---|---|---|
| 01 | LED Interfacing | LED blinking using Port 1 |
| 02 | Stepper Motor | Stepper motor sequence generation |
| 03 | Relay and Buzzer | Relay and buzzer interfacing |

### ARM7 LPC2148

| No. | Practical | Description |
|---|---|---|
| 04 | GLCD Interfacing | Display character output |
| 05 | 4×4 Keypad | Keypad scanning |
| 06 | GPS Interfacing | UART communication with GPS |
| 07 | On-Chip RTC | Real-time clock configuration |
| 08 | SD Card using SPI | SPI communication and SD card command transmission |

## Development Environment

| Component | Tool |
|---|---|
| Operating System | Ubuntu Linux (WSL2) |
| 8051 Compiler | SDCC |
| 8051 Simulator | uCsim (s51) |
| ARM Compiler | ARM GCC Toolchain |
| Code Editor | Visual Studio Code |
| Version Control | Git and GitHub |

## 8051 Compilation and Simulation

Install the required packages:

```bash
sudo apt update
sudo apt install sdcc sdcc-ucsim -y
```

Compile an 8051 program:

```bash
sdcc -mmcs51 --model-small 8051/01_LED_Interfacing.c
```

Run the generated Intel HEX file:

```bash
s51 01_LED_Interfacing.ihx
```

Inspect Port 1 inside the simulator:

```text
get sfr P1
```

## LPC2148 Development

LPC2148 programs require:
- An ARM-compatible C compiler.
- LPC214x device header files.
- Correct peripheral pin configuration.
- Suitable hardware or a compatible simulator for testing.

These programs are intended as starting examples and may require changes according to the actual circuit connections and peripheral configuration.

## Important Notes

- The 8051 examples use SDCC-compatible headers.
- The LPC2148 examples depend on the LPC214x device header and hardware configuration.
- GPS forwarding is not the same as GPS coordinate parsing.
- The SD-card example demonstrates an initial SPI command, not complete SD-card read/write functionality.
- GLCD and keypad programs require matching pin connections.
- Compilation does not guarantee correct hardware operation. Verify each practical with suitable hardware or simulation.

## Learning Objectives

- Understand microcontroller architecture and programming.
- Practise GPIO interfacing.
- Understand UART and SPI communication.
- Work with timers and RTC peripherals.
- Develop embedded C programming skills.
- Learn compilation, debugging, and simulation workflows.

## Author

**Omsai Dasari**

- GitHub: [@CodeWithOmsai77](https://github.com/CodeWithOmsai77)

---

*This repository is maintained as part of academic practical learning and embedded systems development.*

## Practical Validation Checklist

Use this checklist when adapting an example to a physical board or simulator:

- [ ] Confirm the exact MCU variant, clock source, compiler and device header.
- [ ] Verify pin multiplexing and peripheral pin assignments against the device datasheet.
- [ ] Confirm voltage levels, common ground and external component requirements before wiring.
- [ ] Check peripheral status flags and timeouts instead of assuming every transaction succeeds.
- [ ] Record the expected input/output behaviour and test both normal and failure conditions.
- [ ] Separate hardware-dependent validation from compiler-only checks.

## Practical Status and Limitations

The source files are educational starting points. The presence of a program in this repository does not mean it has been validated on every board revision. For each practical, record the board, toolchain version, wiring, test procedure and observed result in its project notes. In particular, distinguish code compilation from successful peripheral operation on hardware.
