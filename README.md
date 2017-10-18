# ESPproMon ©
ESPproMon © Smartphone App for Energy Monitoring with **Appp © Technology**

What is Appp © Technology?

It's **app**liance **p**rofiling which allows you to identify when specific appliances are powered up or powered down etc. It's very much in it's infancy but fully expected to be the next big thing in Smart Energy Monitoring.

![ESPproMon Smartphone energy monitoring and contol app](https://github.com/pieman64/ESPproMon/blob/master/images/ESPproMon%204%20Tabs.png)

**PeaceFair** make some very reasonably priced energy monitors and they have a **user friendly interface** for the ESPproMon system. You will however need the services of a qualified electrician to safely wire up the PeaceFair products. Below is one of their products wired up in our consumer unit.
<p align="center">
<img src="https://github.com/pieman64/ESPproMon/blob/master/images/PZEM-004%20from%20PeaceFair%20installed%20in%20a%20domestic%20electrical%20consumer%20unit.jpg">
</p>

The picture below should be your ultimate goal i.e. a simple **plug and play CT (current transformer)** clipped around the live feed in your consumer unit. The other end of the CT will then be hooked up to your chosen energy monitoring hardware and the Smartphone app does the rest.

![CT sensor in a domestic consumer unit enclosure.](https://github.com/pieman64/ESPproMon/blob/master/images/Consumer%20unit%20with%20current%20transformer.jpg)

Included in this repository are files for the **emonTx** and **Arduino Shield** supplied by [Open Energy Monitor](https://community.openenergymonitor.org/) in **Wales**. You will find the sketches in [this](https://github.com/pieman64/ESPproMon/tree/master/OpenEnergyMonitor) directory.

The **emonTx** is available in kit form for the Arduino Uno and Leonardo. This is the kit we received and found the build procedure very straightforward.

<p align="center">
  <img src="https://github.com/pieman64/ESPproMon/blob/master/images/emonTx%20Arduino%20shield%20components.jpg">
</p>

This is the completed shield fitted to a Leonardo with a DS18B20 sensor and USB2TTL adaptor fitted. It also has the **AC - AC** adaptor that's **essential** if you want to accurately measure Real Power and therefore real Energy costs.

![Comleted emonTx shield](https://github.com/pieman64/ESPproMon/blob/master/images/emonTx%20Arduino%20shield%20with%20Leonardo%20DS18B20%20and%20TTL.jpg)

Actually the shield is not technically complete as we only fitted CT1 and the high precision CT4. We might fit CT2 and CT3 connectors at a later date but for now two connectors is fine for our requirements. 

We have now added the hex and ino files for the **emonPi** but as we don't have an emonPi it's untested and you use the files at your own risk. The emonPi from ![Open Energy Monitor](https://shop.openenergymonitor.com/emonpi-3/) is probably the **safest Energy Monitoring system currently available** and it offers a plug and play solution for anyone that doesn't have formal training with electrical installations.
<p align="center">
  <img src="https://github.com/pieman64/ESPproMon/blob/master/images/emonPi%20complete%20with%20enclosure.jpg">
  <img src="https://github.com/pieman64/ESPproMon/blob/master/images/emonPi%20PCB%20with%20Raspberry%20Pi.jpg">
</p>
If you haven't used the Serial port on your Raspberry Pi before you might want to take a look at these two web pages:

![THE RASPBERRY PI UARTS](https://www.raspberrypi.org/documentation/configuration/uart.md) and 
![Configuring The GPIO Serial Port On Raspbian Jessie](https://spellfoundry.com/2016/05/29/configuring-gpio-serial-port-raspbian-jessie-including-pi-3/)

More details to follow in due course but meanwhile if you have any questions you can open a GitHub issue or contact us via our website at [ESPproMon](https://peacefairapp.com/).
