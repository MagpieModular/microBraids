# microBraids
μBraids in 8HP.

Braids is an amazing module Half the space, twice as amazing.


Note: Since the layout is so cramped and small the PCB does not have component designations marked on them as it would be mostly useless and rip your hair out frustrating. Instead, you should use this easy to navigate build guide or the diptrace file.

What you will need to build this:
This is an advanced build. After you follow the basic build guide and solder in the 0603 & TSSOP components and you will have to flash two microprocessors with two different programmers... It is not insurmountable but if you haven't done a microprocessor based build I would recommend something simpler to start.

Nothing has been altered component-wise from v5 of Braids. Some ICs were shrunk down to TSSOP packages in order to create more space. This means that any future firmware upgrade on Braids or alternate firmware such as Tim Churches Bees in the Trees should load and work fine.

Hardware needed:

FTDI Programmer (removed the jtag header for space reasons)

AVR Programmer

OLED (can be found cheaper elsewhere)

I recommend using and installing the Mutable Instruments Vagrant Dev Environment to Flash the Braids aspect of this with any firmware you like. Flash as you would any normal DIY Mutable Instrument build.

You will then need to install the

    Arduino app
    The Adafruit GFX Library (standard Arduino Library install)
    The Adafruit SSD 1306 Library
    elapsedMillis. Library

The library cannot determine the screen size via software. You have to specify it in the header file. Go into the library folder and open the file Adafruit_SSD1306.h. Toward the top you'll see a section of comments that tell how how to edit the file for different kinds of display. This is a 128x32 SPI OLED.

You can then load the display code

This is Open Source Project

Want to contribute? This project could benefit from the following: Contact us if you are interested in contributing to any of the following:

    OLED reprogramming to show the full name of the parameter and what the timbre & color adjust. There may be space for a 128x64 OLED so there is potential for this to display for more information than the regular 14 segment LEDs braids has.
    Someone to maintain and update the code repository.
    Muffwiggler project thread maintainence 

We are a small 2 person shop and unfortunately do not have time to be able to offer any build support or answer any questions about or troubleshoot your DIY builds.  This is an at your own risk project. For the most part you can safely consider this identical to a regular braids with a few chips reduced in size and an additional atmega chip & circuit to handle the OLED display.


Original CAD file, PCB & Schematic and original design elements provided by Mutable Instruments under creative commons CC-BY-SA-3.0 license.

Our design contributions are provided by Magpie Modular under Creative Commons CC-BY-SA-3.0 license.

Please be advised: This board is 0603 SMT components and thus not suitable for beginners. If you would like a good introduction to the sDIY world we recommend a simpler through-hole kit such as the Mikrophonie and working up in complexity from there.

Before purchasing be ensure you are comfortable with setting up the development environment needed to compile the firmware and flash these units and understand the basic flow of working on microprocessor based builds. That said: The point of providing these boards is that learning to work SMT is not an insurmountable task and with proper research, practice and steady hands you might actually prefer it. (or not)

If you are interested in a simple SMT build in which to start we recommend something analog with a small part count, such as a Links or Shades. Working up from there Branches is a nice easy introduction into microprocessors and then I find all the others about the same.

Support is not available through us nor Mutable Instruments nor the Mutable Instruments forums, please respect their wishes to not want to answer any questions regarding DIY builds and leave them to continue doing what they do best.


 
 
