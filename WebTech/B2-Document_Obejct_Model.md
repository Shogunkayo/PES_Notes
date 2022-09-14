# DOCUMENT OBJECT MODEL
----
- Language and platform independent model used to represent HTML or XML documents
- Defines the logical structure
- All elements are organized in a hierarchical tree-like structure
- Each individual part is called node
- It gives an object oriented representation of the webpage, which can be manipulated by JavaScript

> DOM IS NOT a part of JavaScript. It is constructed by the BROWSER.

![[dom1.png]]
- Document is the root node, and has one child which is the `<html>` element

1. The document or webpage is the document node
2. All HTML elements are element nodes
3. All HTML attributes are attribute nodes 
4. Text inside the HTML elements are text nodes
5. Comments are comment nodes

### Document Fragment
- Lightweight interface of the Document which is not a part of the active DOM tree
- Changes in the fragment are not reflected in the document
- Typically used to compose DOM nodes and append or insert it to the active tree

-> Creating a new document fragment
```
let fragment = new Document Fragment();
```

```
let fragment = document.createDocumentFragment();
```

->`appendChild()` and `insertBefore()` methods are used to insert nodes

### Node
- Generic name of any object in the DOM tree
- An element is a node with a specific node type `Node.ELEMENT_NODE` which is equal to 1


### Accessing Elements

| Access Element by | Method                         |
| ----------------- | ------------------------------ |
| ID                | getElementByID("demo")         |
| Class             | getElementsByClassName("demo") |
| Tag               | getElementsByTagName("p")      |
| Selector(single)  | querySelector("selector")      |
| Selector(all)     | querySelectorAll("selector")   |

- If multiple elements have the same ID,  `getElementByID` returns only the first occurrence
- `getElementsByClassName` ,`getElementsByName` and `getElementsByTagName` return a live NodeList of elements
- CSS selector rules apply for `querySelector` and `querySelectorAll`

#### innerHTML
- The `innerHTML` property sets or returns the HTML content (inner HTML) of an element
- `innerText` is used to obtain text from an element without HTML tags

### Traversing Elements

![[dom2.png]]

-> To get the parrent node of a specified node
```
let parent = node.parentNode;
```
- `parentNode`is read only
- Document and Document Fragment do not have parent nodes, the value will be NULL
- If a new node which hasnt been attached to the DOM tree, its parent node value will also be NULL

-> To get the next sibling 
```
let next_sibling = node.nextElementSibling;
```

-> To get the previous sibling
```
let prev_sibling = node.previousElementSibling;
```

-> `firstChild` and `lastChild` return the first and last child of a node which can be of any type

-> `firstElementChild` and `lastElementChild` return the first and last child element node


### Updating Nodes
-> To change the text, `innerHTML` is used
```
node.innerHTML = 'modified text';
```

-> To change CSS properties, `style` is used
```
node.style.css_property = modified_value;
```
```
node.style.backgroundColor = "yellow";
```

### Deleting Nodes
- The parent node has to be accessed first, and then the child node can be deleted
```
node.parentNode.removeChild(node);
```

-> `node.remove()` method removes the child node directly

->  `node.replaceWith()` and `node.replaceChild()` are used to replace nodes

### Creating Nodes
- Different methods are used to create different types of nodes

-> To create an element node
```
document.createElement('<HTML element>');
```

-> To create a text node
```
document.createTextNode('New text');
```

### Adding Elements to DOM
- Attaching a node to the DOM tree makes it visible in the browser
- `appendChild()` method adds a node to the end of the list of children node of the specified parent node
- If the given child is a refernce to an existing child, the node is moved to the new position
```
node.appendChild(childNode);
```

- `insertBefore()` method inserts a node before a specified sibling node

### Accessing attributes
- `Element.setAttribute(attribute_name, value)` is used to set the attribute
- `Element.getAttribute(attribute_name)` returns the value of the specified attribute


## innerHTML vs createElement
1. `createElement` is more efficient as `innerHTML` reparses and recreates all the DOM nodes inside the parent node
2. `innerHTML` is shorter and cleaner used to add attributes to an element
3. `createElement` is secure, `innerHTML` is vulnerable to injections
4. Using Document Fragment is more efficient when there is looping involved

```
let div = document.querySelector('container');
let fragment = document.createDocumentFragment();
let p;

for(int i=0; i<10; i++){
	p = document.createElement('p');
	p.textContent = 'Paragraph ${i}';
	fragment.appendChild(p);
}

div.appendChild(fragment);
```

-> Using `innerHTML` to add an element
```
let div = document.querySelector(".test");
div.innerHTML += "<p> Hello </p>";
div.innerHTML += "<p class='note>' Hello </p>"
```
