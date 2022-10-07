# REACTJS
---
- Free and open-source JS library for building UX-UI components
- Used to create single page web applications and dynamic client-side applications

### React Elements
- React DOM is made up of React elements
- It is a description of what an actual element should look like

`React.createElement(type, {properties}, children)`

- `type` is the type of element to create, usually a html tag
- `properties` are the attributes of the html tag
- `children` represents the content inside the tag

Example: `React.createElement("h1", {id: "recipe-0", 'data-type': "title"}, "Baked Salmon")`

![react_dom.png](https://github.com/Shogunkayo/PES_Notes/blob/main/WebTech/Images/react_dom.png)

## JSX
- Extension to JavaScript which allows mixing of HTML tags with JavaScript
- Stands for JavaScript XML, used in React applications
- Babel is a transcompiler which translates markup or programming language into JavaScript

With JSX:-
```
<div id="content"></div>
<script type="text/babel">
	ReactDOM.render(<h1>Welcome</h1>, document.getElementById("content"))
</script>
```

Without JSX:-
```
<div id="content"></div>
<script>
	ReactDOM.render(React.createElement("h1", "null", "Welcome"), document.getElementById("content"))
</script>
```

## Component
- Defines the visuals and interactions

1. Stateless Functional Components
   - Includes simple JS functions and immutable properties
   - Uses hooks to achieve functionality 
   - Used mainly for UI
2. Stateful Class Component
   - Classes that extend the `Component` class from the React librabry
   - Must inlcude the `render` method which returns HTML
```
class HelloWorld extends React.Component{ 
	render(){ 
	return <p>Hello, componentized world!</p>; 
	}
}
```

- `render()` method is called when React needs to display something
- Lifecycle functions provide hooks into various stages of the component formation and events

- Components can have parameters and the arguements can be passed while rendering

## Properties
- Properties are equivalent to attributes in HTML
- Used to pass data from one component to another
Example of creating a Component and passing Properties
```
<div id="container"></div>
<script type="text/babel">
	class Hello extends React.Component{
		render(){
			return <h1>Hello,{this.props.getname}</h1>
		};
}

	ReactDOM.render(<Hello getname="Xon Cina" />, document.getElementById("container"));
</script>
```

- `this.props.{propname}` used to add a property to the element
- `this.props.children` refers to the child elements present within the componenet and will render/invoke them

- The properties being passed can be validated 
- The specification is supplied in the form of a static object called `propTypes` with the name of the property as key and the validator as value 
- Property validations is done only in development mode
- A warning message is shown in the console when the validation fails, but the arguement is renderer regardless
```
// Component
class ComponentExample extends React.Component{
    render(){
        return(
                <div>
                    {/* printing all props */}
                    <h1>
                        {this.props.arrayProp}
                        <br />
 
                        {this.props.stringProp}
                        <br />
 
                        {this.props.numberProp}
                        <br />
 
                        {this.props.boolProp}
                        <br />
                    </h1>
                </div>
            );
    }
}
 
// Validating prop types
ComponentExample.propTypes = {
    arrayProp: PropTypes.array,
    stringProp: PropTypes.string,
    numberProp: PropTypes.number,
    boolProp: PropTypes.bool,
}
```

- `defaultProps`  is used to set default values to the properties of a component
```
ComponentExample.defaultProps = {
    arrayProp: ['Ram', 'Shyam', 'Raghav'],
    stringProp: "GeeksforGeeks",
    numberProp: "10",
    boolProp: true,
}
```

## Styling
- There are different ways of styling a React component

#### 1. Inline CSS
- An object with the styling information is created
- `style` attribute is used to refer to that object
- Camelcase notation is used to refer to css properties (Eg: backgroundColor instead of background-color)
```
 class Letter extends React.Component{
	render(){
		var letter_style = {
			fontSize: "40px",
			textAlign: "center",
			backgroundColor: this.props.bgcolor,
			color: "cyan",
			padding: "30px"
		}

		return(
			<h1 style={letter_style}>{this.props.children}</h1>
		)
	}
}

ReactDOM.render(
	<div>
		<Letter bgcolor="white">White</Letter>
		<Letter bgcolor="grey">Grey</Letter>
		<Letter bgcolor="black">Black</Letter>
	</div>,
	document.getElementById("container")
)
```

#### 2. CSS-in-JS

#### 3. SASS or SCSS

## Complex Components
- Components which use other user defined components
- Also called component composition

![complex_component.png](https://github.com/Shogunkayo/PES_Notes/blob/main/WebTech/Images/complex_component.png)

The above component can be broken up into 3 - image rendering, caption rendering and link rendering

```
class MainComponent extends React.Component{
	render(){
		return(
			<div>
				<ImageComponent/>
				<CaptionComponent/>
				<LinkComponent/>    
			</div>
		)
	}
}

class ImageComponent extends React.Component{
	render(){
		return(
			<img src="demo.png" />
		)
	}
}

class CaptionComponent extends React.Component{
	render(){
		return(
			<p>Tiger in the woods</p>
		)
	}
}

class LinkComponent extends React.Component{
	render(){
		return(
			<a href="www.tigerwoods.com"> Click me</a>
		)
	}
}

ReactDOM.render(<MainComponent/>, document.getElementById("container"))
```

### Transferring Properties
- To make the above code dynamic, we can use `this.props`
- When rendering the main component, the properties passed to it needs to be transferred to the individual components
- This is done by using the `...`(spread) operator

```
class MainComponent extends React.Component{
	render(){
		return(
			<div>
				<ImageComponent{...this.props}/>
				<CaptionComponent{...this.props}/>
				<LinkComponent{...this.props}/>    
			</div>
		)
	}
}

class ImageComponent extends React.Component{
	render(){
		return(
			<img src={this.props.src} />
		)
	}
}

class CaptionComponent extends React.Component{
	render(){
		return(
			<p>{this.props.caption}</p>
		)
	}
}

class LinkComponent extends React.Component{
	render(){
		return(
			<a href={this.props.link}> Click me</a>
		)
	}
}

ReactDOM.render(<MainComponent src="demo.png" caption="Tiger in the Woods" link="www.tigerwoods.com"/>, document.getElementById("container"))
```

# [[States]]
