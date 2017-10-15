# ESPproMon ©
ESPproMon © Smartphone App for Energy Monitoring with **Appp © Technology**

What is Appp © Technology?

It's **app**liance **p**rofiling which allows you to identify when specific appliances are powered up or powered down etc. It's very much in it's infancy but fully expected to be the next big thing in Smart Energy Monitoring.

![ESPproMon Smartphone energy monitoring and contol app](https://github.com/pieman64/ESPproMon/blob/master/images/ESPproMon%204%20Tabs.png)

The pitcture below should be your ultimate goal i.e. a simple **plug and play CT (current transformer)** clipped around the live feed in your consumer unit. The CT will then be hooked up to your chosen energy monitoring hardware and the Smartphone app does the rest.

![CT sensor in a domestic consumer unit enclosure.](https://github.com/pieman64/ESPproMon/blob/master/images/Consumer%20unit%20with%20CT.jpg)

The first files we are including in this repository are for the emonTx and Arduino Shield supplied by [Open Energy Monitor](https://community.openenergymonitor.org/) Arduino in **Wales**. You will find the sketches in [this](https://github.com/pieman64/ESPproMon/tree/master/OpenEnergyMonitor) directory.

The emonTx is available in kit form for the Arduino Uno and Leonardo. This is the kit we received and found the build procedure very straightforward.

![emonTx Arduino shield](https://github.com/pieman64/ESPproMon/blob/master/images/emonTx%20Arduino%20shield%20components.jpg)

This is the completed shield fitted to a Leonardo with a DS18B20 sensor and USB2TTL adaptor fitted. It also has the **AC - AC** adaptor that's essential if you want to accurately measure Real Power and therefore real Energy costs.

![Comleted emonTx shield](https://github.com/pieman64/ESPproMon/blob/master/images/emonTx%20Arduino%20shield%20with%20Leonardo%20DS18B20%20and%20TTL.jpg)

Actually the shield is not technically complete as we only fitted CT1 and the high precision CT4. We might fit CT2 and CT3 connectors at a later date but for now two connectors is fine for our requirements. 

More details to follow in due course.
