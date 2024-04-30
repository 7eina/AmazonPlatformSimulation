# Amazon Platform Sim

This application is designed for a logistics company modeled after Amazon's distribution system. It efficiently manages the tracking of orders from the moment they arrive at local distribution centers—akin to Canada Post or UPS locations—until they are delivered to customers. The application focuses on the segment of the supply chain from distributors to customers, ensuring transparency and real-time updates for each order. Note that the transportation of orders from the central warehouse to the distributors is automated and not tracked within this system.

Created: Summer2023

## Compatibility
- **Ubuntu**: This software is fully compatible with Ubuntu and can be compiled and executed in any standard Ubuntu environment.
- **VirtualBox - Virtualizing Ubuntu on Windows**: The software can be run on Ubuntu virtualized through VirtualBox on a Windows host. Ensure that your VirtualBox setup has adequate resources allocated and Ubuntu installed for smooth operation.
- **CLion on Windows**: The project can be loaded and executed in the CLion IDE on Windows. This requires a C++ environment setup in CLion, including the MinGW or Cygwin toolchains.

## System Requirements
- **Linux**: GCC compiler and standard C++ libraries.
- **Windows**: CLion with MinGW or Cygwin, VirtualBox for virtualizing Linux.

# Logistics Tracking System

## Project Overview
This application models a logistics company similar to Amazon, focusing on tracking orders from local distributors to customer delivery. The system automates the segment from the central warehouse to local distributors and provides real-time tracking of orders until they reach the customers.

## File Structure
- **Header and Source Files**: Includes all classes defined as per the system's requirements.
  - `defs.h`: Contains global definitions.
  - `Entity.h/.cc`: Base class for distributors and drivers, containing user information.
  - `Location.h/.cc`: Manages map coordinates and street names.
  - `Order.h/.cc`: Manages customer orders from the warehouse.
  - `Distributor.h/.cc`: Represents a distribution location.
  - `Driver.h/.cc`: Manages order pickups and deliveries.
  - `Queue.h/.cc`: Implements a FIFO data structure for storing orders.
  - `Warehouse.h/.cc`: Central hub for managing products and orders.
  - `Controller.cc`: Controls interactions between the warehouse and the user interface.
  - `View.h/.cc`: Handles user input and output.
- **UML Diagram**: `A3_UML_Diagram.pdf` details the class interactions and structure.

## Compilation and Execution
1. **Compile the Application**:
   ```bash
   make

2. **Run Application**:
      ```bash
      ./a3
