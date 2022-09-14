# Introduction
----

- HTML - Hyper Text Markup Language
- It is not an actual programming language
- HTML tags structure content

```
<html>
	<head>
		<title></title>
	</head>
	<body>
	</body>
</html>
```

- CSS - Cascading Style Sheets
- Used to style webpages - change colors, font, postions etc

- index.html is the default home page file name a browser looks for in a website

- DOCTYPE defines the document as a html document so that a browser can render correctly 
```
<!DOCTYPE html>
```



# BASIC HTML TAGS
----

| Tags       | Purpose                                                         |
| ---------- | --------------------------------------------------------------- |
| strong     | Makes the text bold                                             |
| em         | Italicises the text                                             |
| small      | Makes the text smaller                                          |
| h1         | Largest heading                                                 |
| h6         | Smallest heading                                                |
| p          | Starts a paragraph                                              |
| ul         | Starts an unordered list                                        |
| ol         | Starts an ordered list                                          |
| li         | List element                                                    |
| div        | Creates a division                                              |
| span       | Way of adding CSS or JS hook                                    |
| br         | Causes a line break                                             |
| hr         | Draws a horizontal line                                         |
| img        | Inserts an image, requires a source attribute                   |
| a          | Anchor tag, href attribute is required to create hyperlinks     |
| blockquote | Creates a quote block, cite attribute is used to display source |



# FORMS
----

```
  <form>
    <label for="username">Enter Username</label>
    <input type="text" id="username">
    <br><br>
    <label for="email">Enter Email</label>
    <input type="email" id="email">
    <br><br>
    <label for="password">Enter Password</label>
    <input type="password" id="password">
</form>

```

- The name attribute can be used for server side processing
```
<input type="password" id="password" name="password">
```

- Name attribute is also used to group different input elements
```
<input type="radio" id="gender1" name="gender" value="M">
<label for="gender1">Male</label>
<input type="radio" id="gender2" name="gender" value="F">
<label for="gender2">Female</label>
```
- The value attribute returns the value to the server

- Select tag is used for drop-down menus
```
<label for="question">Select Question</label>
<select name="question" id="question">
    <option value="q1">What color is your laptop</option>
    <option value="q2">What color is your vegetable</option>
    <option value="q3">What color is your fruit</option>
</select>
```

- Creating a textbox
```
<label for="address">Enter Address</label><br>
<textarea name="address" id="address" col="20" rows="10" placeholder="Enter here"></textarea>
```

- Submitting the form
```           
<input type="submit" id="submit" class="submit">
```

- Placeholder attribute can be used for all input types
- Action attribute is used to perform some action when the form is submitted
- Required attribute makes the particular input type required to submit the form

##### [MORE TAGS](https://www.w3schools.com/html/html_forms.asp)

### Inline elements
- Dont take up any more room than they need
- span, em, a, strong
- They sit next to each other untill they run out of space

### Block-level elements
- Take up whole width of space irrespective of content
- h1, p, div, blockquote
- Always starts on a new line



# CSS
-----

- A stylesheet is a lsit of css rules
- Selectors are used to target html elements

```
<style>
html_tag:{
	color: red;
	font-szie: 20px;
	background-color: blue;
}
</style>
```

- When changing font family, use [web safe fonts](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbTdHeEpSeEd0cUJxcUp5YXNzWFhLbjQxVnVzd3xBQ3Jtc0trTk9VUG1KODFnZmI3ZUpMZEhCVElaR2JvY2JTaTBtYjlOMEVvRUtkRHJvUXZ0N1Vpd29qdjNraU9FTGd0djF6a3VZeHMxUjN2OFdselJFQ3lvbTJ0ZWxOVXFnYTI0WEs2NTByTkxUbXQtZzUzY3p1TQ&q=https%3A%2F%2Fwww.w3schools.com%2Fcssref%2Fcss_websafe_fonts.asp&v=D3iEE29ZXRM) 


## Common CSS Tags
| General          | Paragraph      | List               |
| ---------------- | -------------- | ------------------ |
| color            | line-height    | border             |
| font-size        | letter-spacing | border-(direction) |
| font-family      | column-count   | list-style-type    |
| text-align       | column-gap     | text-shadow        |
| text-decoration  |                |                    |
| background-color |                |                    |
| margin           |                |                    |
| padding          |                |                    |
| font-weight      |                |                    |
| text-transform   |                |                    | 


- Border syntax
```
border: size style color
```

- Text shadow syntax
```
text-shadow: offset_side offset_vertical shadow_color
```

 - \# is used to indicate hexcode while using colors

- Inline elements can be made block-leve and vice versa by
```
display: block
```

- Margin for inline elements is only to the left and right, but all around for block-level elements

- Padding collapses for inline elements when the size of browser is changed
- Margin collapses for block-level elements
- "inline-block" prevents collapses and keeps the elements in the same line

- Each html element has certain default browser stylesheets



# CSS Selectors
----

- Used to select a certain block of text

- Classes - 
```
.class_name{
	properties
}
```

- Id -
```
#id_name{
	properties
}
```

- Descendant selectors -
```
div p a{
properties
}
```

- Attribute
```
a[href]{
	properties
}
```
```
a[href = "url"]{
	properties
}
```
```
a[href*="something_included"]{
	properties
}
```
```
a[href$="ends_in_something"]{
	
}
```



# Cascade
-----
- HTML elements can inherit CSS properties that are applied to their parents
```
<div>
	<p> <a> </a> </p>
<div>
```
Properties applied to div are inherited by p and a tags
Margin, padding, background styles, borders are not inherited

- To force inheritance,
```
div{
	border: 1px solid green;
	margin: 100px;
}
p{
	border = inherit;
	margin = inherit
}
```

- Whatever is declared at the last has higher precedence, and inheritance can be overriden

- A more specific selector has higher precedence
```
div p{

}
p{

}
```
div p has higher precedence than p for the paragraph tags under div

- [More info about selectors](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbHhXb3hCNndUMXZvODlLck1jVWhyekVkejFZZ3xBQ3Jtc0tsczVpVGkwM093ZEs5N2pnUlJSSkg0d04tNDJCSnY3ZnpUZDdSa3dwMXdCUE9CaVNGdkF1U2J0blBqQnVoSUlTVjN2VGtSNmNQYnJOTDhQemtaMzF5Vkd6UEs5QzZ1VnRPOUZTMjdHOEYxRER3dWRwMA&q=https%3A%2F%2Fdeveloper.mozilla.org%2Fen-US%2Fdocs%2FWeb%2FCSS%2FCascade&v=FHZn6706e3Q)

# POSITION AND LAYOUT
----

1. Static
2. Relative
3. Fixed
4. Absolute
5. Sticky

- Parent element is positioned relatively so that a child element can be positioned absolutely

# HTML5 Semantic Tags
------
- Make code more descriptive

| Tags    | Purpose                                        |
| ------- | ---------------------------------------------- |
| main    | main content of webpage which is unique        |
| section | defines a certain section                      |
| article | defines a block to be a part of an article     |
| aside   | defines some content related to something else |
| header  | for the header of the website                  |
| footer  | for the footer of the website                  |
| nav     | for navigation                                               |


# PSUEDO CLASSES
-----
- Special keywords added to selectors so that a particular sate of an element can be targerted
- hover, focus, valid, first-child
- [All keywords]([https://www.w3schools.com/css/css_pse...](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbWQ1b3RZRXo5MTJkSFRraURYNjRFRV9lbXhkd3xBQ3Jtc0trU2NwQ3NocGdrazkySVNPbThHYnJ5UkVRU013bUxtdFkwdlIzZVRWYURKLURvT2JYZmZxT3poSWszOFlkbjdST2M3SnduT3ZiaDdGUlNOVUw5SzVsUVd3X2pfTVM4MkZCc3hWakRIRktyaWpMMnJhNA&q=https%3A%2F%2Fwww.w3schools.com%2Fcss%2Fcss_pseudo_elements.asp&v=FMu2cKWD90g))
- Pseudo elements - first-line, first-word

# FURTHER LINKS
---
- Media Queries : [[A1-Media Queries]]
- Audio and Video: [[A2-Audio_Video]]
- Canvas and SVG[[A3-Canvas_SVG]]