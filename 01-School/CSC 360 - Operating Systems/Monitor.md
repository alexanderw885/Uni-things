high-level abstraction (Object Oriented) that provides convenient and effective method for [[Synchronization]]

A monitor is essentially a class of private data, and a restriction that only only method from the monitor can be active at any point in time

Java and C# support monitor. Every object has a monitor, use "synchronized" to declare a method or code block
C does not, but you can simulate it with mutex+convar

they have guaranteed mutual exclusion and thread cooperation