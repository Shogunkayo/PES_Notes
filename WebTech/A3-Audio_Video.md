# AUDIO
---
- `<audio>` tag is used to play audio in html pages
```
<audio src="file" controls></audio>
```
- The tag comes with many inline global attributes 

| Attribute | Function                                                           |
| --------- | ------------------------------------------------------------------ |
| autoplay  | audio will start playing as soon as it is ready                    |
| controls  | control options will be displayed in the browser                   |
| loop      | audio will start playing again after ending                        |
| preload   | audio will be loaded at page load, ignored if autoplay is included |
| src       | url of the file to be played                                       | 


# VIDEO
---
- `<video>` tag is used

| Attribute | Function                                         |
| --------- | ------------------------------------------------ |
| audio     | current state of audio, only "muted" is allowed  |
| autoplay  | plays video as soon as it is ready               |
| controls  | control options will be displayed in the browser |
| height    | sets the height of the player in pixels          |
| width     | sets the width of the player in pixels           |
| loop      | video will start playing again after ending      |
| poster    | url of the image representing the video          |
| preload   | similar function as audio preload                |
| src       | url of the file to be played                     | 


# PROGRESS
---
- `<progress>` is used to create a progress bar
-  Can be in the form of a spinning wheel or a progress bar
-  `max` and `value` attributes are used to define how much progress has been made towards completion

[Styling Progress Elements](https://css-tricks.com/html5-progress-element/)



