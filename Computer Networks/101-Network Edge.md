# EDGE DEVICES
--- 
- The end systems/hosts which are at the 'edges' of a network 
- First router connect to the end system is called edge router
- Access network allows the end system to connect to the internet

## Access Networks
- The two most prevalent types of broadband residential access are digital subscriber line and cable

### 1. Digital Subscriber Line - DSL
- wired medium - coaxial or optical fibres
- using existing telephone line to central office DSLAM(digital service line access multiplexer)
- data is transmitted over DSL phone line to the internet
- voice is transmitted over  DSL phone line to the telephone net
- Frequency Division Multiplexing -> different frequency bands for uploading, downloading and talking channels:
	- High speed downstream channel: 50 kHz to 1MHz
	- Medium speed upstream channel: 4kHz to 50kHz
	- Ordinary two-way telephone channel: 0 to 4kHz
- simarly, different transmission rate
- called asymmetric access as different dowstream and upstream rates

![dsl.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/dsl.png)

### 2. Cable-based access
- Makes use of the cable television company's existing cable television infrastructure
- Internet access is from the same company that provides cable television
- Also called Hybrid Fiber Coax as both fiber and coaxial cables are employed in this system 
![cable.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/cable.png)
- Requires special modems called cable modems. The Cable Modem Terminating System serves a similar function as the DSLAM - turning the analog signal sent from the cable modems to digital format
- Cable access is shared broadcast medium - Every packet sent by the head end travels downstream on every link to every home and every packet sent by a home travels on the upstream channel to the head end
- If several users are simultaneously downloading a video file on the downstream channel, the actual rate will be significantly less
- A distributed multiple access protocol is needed to coordinate transmissions and avoid collisions in the upstream channel

### Fiber To The Home (FTTH)
- Provides an optical fiber path from the CO directly to the home
- Faster than the above two access methods
- Two types : Active Optical Networks and Passive Optical Networks

FFTH using PON: 
- ![ftth.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/ftth.png)
- Each home has an Optical Network Terminator which is connected by dedicated optical fiber to a neighbourhood splitter
- The splitter connects multiple homes to a single shared optical fiber which is connected to an Optical Line Terminator

## Types of Networks
- SOHO - smallest network
- Different types of networks:
	- Personal Area Network
	- Local Area Network: Wired(Ethernet) or Wireless(Wifi)
	- Metropolitan Area Network
	- Wide Area Network: connection of LANs

# Physical Media
---- 
A source end system first transmits a bit, and shortly thereafter the first router in the series recieves the bit; the first router then transmits the bit, and shortly thereafter the second router receives the bit; and so on. The bit passes through a series of transmitter-receiver pairs. For each transmitter-receiver pair, the bit is sent by propogating electromagnetic waves or optical pulses across a physical medium.
- Can take many shapes and forms and need not be of the same type for each transmitter-receiver pai along the path
- Examples: twisted-pair copper wire, coaxial cable, multimode fiber-optic cable
- Two categorires: guided and unguided media
- The waves are guided along a solid meidum in guided media such as a fiber-optic cable
- The waves propagate in the atmostphere in unguided media such as in wireless LAN or digital satellit e channel

### Twisted-Pair Copper Wire
- Least expensive and most commonly used used guided transmission medium
- Has been used by telephone networks
- Modern twisted pai technology (category 6a cable) can achieve data rates of 10 Gbps for distances up to 100m

### Coaxial Cable
- Consists of two copper conductors which are concentric, instead of parallel like in twisted-pair
- Commonly used in cable television systems
- Used as a guided shared medium

### Fiber Optics
- Thin, flexible medium that conducts pulses of light, with each pulse representing a bit
- Immune to electromagnetic interference and are very hard to tap

### Terrestial Radio Channels
- Radio channels carry signals in electromagnetic spectrum
- Require no physical wire to be installed
- Can penetrate walls and provide connectivity to a mobile user
- Can potentially carry a signal for long distances

### Satellite Radio Channels
- A communication satellite links two or more Earth-based microwave transmitter/receiver known as ground stations
- The satellite receives transmissions on one frequency band, regenerates the signal using a repeater, and transmits the signal on another frequency
- Two types of satellite: Geostationary satellites nad Low-Earth Orbiting satellites
