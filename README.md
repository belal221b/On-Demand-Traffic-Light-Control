# **On Demand Traffic Light Control**
  This project is a simulation of a traffic light control system using C language and Proteus. The project aims to control the traffic light system according to the demand of pedestrians and cars. The system has six LEDs, three for cars, and three for pedestrians, and a button for pedestrians to request crossing the road.

# **System Description**
### **System Overview**
![353603615_618931086839123_3390931127096568107_n](https://github.com/belal221b/Payment-Application/assets/84633317/6964ed89-5fa0-48eb-99bb-fed8bb85c4e6)
  The system aims to provide an on-demand traffic control system. It includes a pedestrian button to allow for pedestrians to pass.

### **System Functionality**
  The system can detect when the button is pressed. Then, based on current state it would decide what to do. It allows pedestrians to walk by making sure cars are stopped first. Refer to Flow Chart for more information.

# **System Design**
### **System Requirements**
The system consists of:
- AVR Atmega32 (1MHz)
- 2 Green LEDs
- 2 Yellow LEDs
- 2 Red LEDs
- 6 resistors (300 Ohm)
- 1 resistor (10k Ohm)
- 1 Push Button

### **System Environment**
  The program has been tested on Proteus simulator provided by LabCenter. It should be used in traffic light control systems on streets with a pedestrian push button included to allow for full system functionality.

### **Input & Output Formats**
  The only system input is in the form of the pedestrian push button. When it comes to output it handles 6 LEDs at once given the current state, time and push button press state.
  
# **Flow Chart**
![image](https://github.com/belal221b/Payment-Application/assets/84633317/0b750130-47a8-43d1-9717-751950a7bb76)


# **Project Components**
- app.h: header file for the application
- GPIO.h: header file for the AVR GPIO driver
- led.h: header file for the LED driver
- button.h: header file for the button driver

# **app.h**
This header file contains the application's main functionality and includes the following functions:

### **void blink()**
This function is used to blink the pedestrian green LED while it's turned on.

### **void interruptEnd()**
This function is responsible for ending the interrupt triggered by the pedestrian button.

### **void pedestrian_led_ON(LED_NAME ledName)**
This function is used to turn on the pedestrian LEDs according to their corresponding LED_NAME.

### **void car_led_ON(LED_NAME ledName)**
This function is used to turn on the car LEDs according to their corresponding LED_NAME.

### **void leds_start()**
This function is used to initialize and set the direction of all the LEDs and buttons used in the project.

### **int app(void)**
This function is the main function of the application, responsible for controlling the traffic light system based on the demand of cars and pedestrians.

# **GPIO.h**
This header file contains the functions used to manipulate the General Purpose Input/Output (GPIO) pins and ports. The functions include:

### **GPIO_ERROR_STATE GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)**
This function is used to set the direction of a specific GPIO pin as either input or output.

### **GPIO_ERROR_STATE GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)**
This function is used to write a value (either high or low) to a specific GPIO pin.

### **uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)**
This function is used to read and return the value of a specific GPIO pin.

### **GPIO_ERROR_STATE GPIO_setupPortDirection(uint8 port_num, uint8 direction)**
This function is used to set the direction of all GPIO pins in a specific port as either input or output.

### **GPIO_ERROR_STATE GPIO_writePort(uint8 port_num, uint8 value)**
This function is used to write a value (either high or low) to all GPIO pins in a specific port.

### **uint8 GPIO_readPort(uint8 port_num)**
This function is used to read and return the value of all GPIO pins in a specific port.

# **led.h**
This header file contains the functions used to manipulate the LEDs. The functions include:

### **LED_ERROR_STATE led_init(const Led_ConfigType * ConfigPtr)**
This function is used to initialize all the LEDs used in the project according to their configurations.

### **LED_ERROR_STATE led_on(LED_NAME ledName)**
This function is used to turn on a specific LED according to its corresponding LED_NAME.

### **LED_ERROR_STATE led_off(LED_NAME ledName)**
This function is used to turn off a specific LED according to its corresponding LED_NAME.

### **LED_STATE led_state(LED_NAME ledName)**
This function is used to read and return the state (either on or off) of a specific LED according to its corresponding LED_NAME.

# **button.h**
This header file contains the functions used to manipulate the pedestrian button. The functions include:

### **BUTTON_ERROR_STATE button_init(const Button_ConfigType * ConfigPtr)**
This function is used to initialize the pedestrian button according to its configuration.

### **BUTTON_STATE butttonState()**
This function is used to read and return the state (either on or off) of the pedestrian button.

### **BUTTON_ERROR_STATE pushButton()**
This function is used to simulate the pressing of the pedestrian button in the Proteus simulation.


# **Proteus Simulation**
The project includes a Proteus simulation file that demonstrates how the traffic light system works.

# **How to Run the Project**
The project can be run using a C compiler and Proteus software. The C files can be compiled and linked using a C compiler, and the Proteus simulation file can be opened using Proteus software.

# **Contributing**
This On Demand Traffic Light Control Project was created by Belal Mohamed..
