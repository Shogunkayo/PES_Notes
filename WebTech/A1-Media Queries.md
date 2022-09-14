# RESPONSIVE DESIGN
----

- Media queries tell the browser how to style an element at a particular viewpoint dimension
- Viewport meta tag tells the browser what width the viewpoint should be

### Setting up the viewport
```
<meta name="viewport" content="width=device-width, initial scale=1.0">
```

### Making media queries
```
@media screen and (max-width: 700px){
    .banner .welcome{
        position: relative;
        text-align: center;
    }
    .banner .welcome h2{
        font-size: 20px;
    }
    .banner .welcome br{
        display: none;
    }
    .banner .welcome span{
        font-size: 1em;
    }
    .images li{
        width: 100%;
        margin: 20px auto;
        display: block;
    }
}
```

https://www.youtube.com/watch?v=Xig7NsIE6DI