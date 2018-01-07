# ESPproMon
ESPproMon Smartphone App for Energy Monitoring and Control with **Appp Technology**

What is Appp Technology?

It's **app**liance **p**rofiling which allows you to identify when specific appliances are powered up or powered down etc. It's very much in it's infancy but fully expected to be the **next big thing in Smart Energy Monitoring**.

<p align="center">
<img src="https://github.com/pieman64/ESPproMon/blob/master/images/ESPproMon%20Tab%201%20and%202%20dark%20halfsize.png" alt="ESPproMon Smartphone Energy Monitoring and Control app tabs 1 and 2">
</p>

<p align="center">
<img src="https://github.com/pieman64/ESPproMon/blob/master/images/ESPproMon%20Tab%203%20and%204%20dark%20halfsize.png" alt="ESPproMon Smartphone Energy Monitoring and Control app tabs 3 and 4">
</p>

**PeaceFair** make some very reasonably priced energy monitors and they have a **user friendly interface** for the ESPproMon system. You will however need the services of a qualified electrician to safely wire up the PeaceFair products. Below is one of their products wired up in our consumer unit and providing **very accurate data**.

<p align="center">
<img src="https://github.com/pieman64/ESPproMon/blob/master/images/PZEM-004%20from%20PeaceFair%20installed%20in%20a%20domestic%20electrical%20consumer%20unit.jpg" alt="PZEM-004 Energy Monitor">
</p>

The picture below is a simple **plug and play CT (current transformer)** clipped around the live feed of our consumer unit. The other end of the CT is hooked up to your chosen energy monitoring hardware and the Smartphone app does the rest.

<p align="center">
<img src="https://github.com/pieman64/ESPproMon/blob/master/images/Consumer%20unit%20with%20current%20transformer.jpg" alt="Consumer unit with current transformer">
</p>

Included in this repository are files for the **emonTx** and **Arduino Shield** supplied by [Open Energy Monitor](https://community.openenergymonitor.org/) in **Wales**. You will find the sketches in [this](https://github.com/pieman64/ESPproMon/tree/master/OpenEnergyMonitor) directory.

The **emonTx** is available in kit form for the Arduino Uno and Leonardo. This is the kit we received and found the build procedure to be very straightforward.

<p align="center">
  <img src="https://github.com/pieman64/ESPproMon/blob/master/images/emonTx%20Arduino%20shield%20components.jpg" alt="emonTx Arduino shield in kit form">
</p>

This is the completed shield fitted to a Leonardo with a DS18B20 sensor and USB2TTL adaptor. It also has the **AC - AC** adaptor that's **essential** if you want to accurately measure Real Power and therefore real Energy costs.

<p align="center">
<img src="https://github.com/pieman64/ESPproMon/blob/master/images/emonTx%20Arduino%20shield%20with%20Leonardo%20DS18B20%20and%20TTL.jpg" alt="emonTx shield with USB2TTL">
</p>

Actually the shield is not technically complete as we only fitted CT1 and CT4. Please note CT4 is a **regular current transformer port** on the shield, unlike the emonTx where CT4 is a **high precision port** up to a maximum of 4.5KW. Although you might use less than 4.5KW most of the time, there will be times when your whole house consumption goes above this figure so the emonTx firmware is set to use CT3.
**For the shield the firmware is set to use CT4**.

Below is a photograph of the emonTx (not shield) and you can just see the USB2TTL connector cables. Only 2 pins are required to be connected to the ESP for use with ESPproMon but you will need a full USB2TTL adaptor to flash the modified sketch to your emonTx. We recommend this [adaptor](https://shop.openenergymonitor.com/programmer-usb-to-serial-uart/) from Open Energy Monitor or at least one with a RST pin. We have included the modified hex files for the emonTx (not shield) so you can flash the firmware wih **avrdude** (Windows or Linux) if you don't already have the Arduino IDE installed.

<p align="center">
  <img src="https://github.com/pieman64/ESPproMon/blob/master/images/emonTx%20with%20TTL.jpg" alt="emonTx with USB2TTL">
</p>

We have included the hex and ino files for the **emonPi** but as we don't have an emonPi it's untested and you use the files at your own risk. The emonPi from ![Open Energy Monitor](https://shop.openenergymonitor.com/emonpi-3/) is probably the **safest Energy Monitoring system currently available** and it offers a plug and play solution for anyone that doesn't have formal training with electrical installations.
<p align="center">
  <img src="https://github.com/pieman64/ESPproMon/blob/master/images/emonPi%20complete%20with%20enclosure.jpg" alt="emonPi from Open Energy Monitor">
  <img src="https://github.com/pieman64/ESPproMon/blob/master/images/emonPi%20PCB%20with%20Raspberry%20Pi.jpg" alt="emonPi circuit board">
</p>
If you haven't used the Serial port on your **Raspberry Pi** before you might want to take a look at these two web pages:

![THE RASPBERRY PI UARTS](https://www.raspberrypi.org/documentation/configuration/uart.md) and 
![Configuring The GPIO Serial Port On Raspbian Jessie](https://spellfoundry.com/2016/05/29/configuring-gpio-serial-port-raspbian-jessie-including-pi-3/)

ESPproMon can also be used with the **ACS712** (5A, 20 and 30A) from **Allegro MicroSystems** and details are available at [ESPecoMon](https://github.com/pieman64/ESPecoMon)

If you have any questions you can open a GitHub issue or contact us via our website at [ESPproMon](https://ESPproMon.com/).
