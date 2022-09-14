# GEOLOCATORS
----
- Enables the web application to obtain geographical location of the client
- The client has to accept to share their location
- `navigator.geolocation` object is used
- The geolocation property is read-only

- The object has two primary functions
  1. `getCurrentPosition()` - returns the location of the visitor as a one-time snapshot
  2. `watchPosition()` - returns the location of the visitor everytime their location changes
- Both the functions take a success callback function, an error callback function and a geolocation options object as parameters
![geo1.png](https://github.com/Shogunkayo/PES_Notes/blob/main/WebTech/Images/geo1.png)

-> Getting the coordinates of the user
```
<p id="demo"></p>
        <script>
            if (navigator.geolocation){
                navigator.geolocation.getCurrentPosition(showPosition);
            } 
            else{
                document.getElementById("demo").innerHTML =
                "Geolocation is not supported by this browser.";
            }

            function showPosition(position){
                document.getElementById("demo").innerHTML =
                "Latitude: " + position.coords.latitude +
                "Longitude: " + position.coords.longitude;
            }
        </script>
```
