#### A few gotchas when working with D3

***

##### Good location for code

[Canonical website](https://d3js.org/getting-started#d3-in-vanilla-html) 
which just involves vanilla D3.


***

##### Cross-origin requests

The examples cannot be started up in the browser like in the
days-of-old. So you need to install a little trivial webserver, with
the files for the project served.

```
npm install -g http-server
http-server ./<dirname> -p 8080
```

It is also possible to do this with built-in Python:

```
python3 -m http.server -d ./<dirname> 8080
```

***

##### Working with data

**TAB MEANS TAB!**

In `vi` this means using something like `ctrl-V <tab>` or disabling
expandtab via `:set expandtab!`

In Visual Studio Code, need to:
* Look at the bottom of the window
* Find where it refers to the number of spaces per tab (if that has
been set already).
* By clicking on this bar, options come up include `indent using
tabs`.
* (And one can switch back and forth between tabs and spaces, of
course).

***

##### Browser forcing

To force a reload of all code, including cached JavaScript:
* macOS: `shift-cmd-R`

Also possible to disable the cache.
* `> Developer Tools`
* `Network` tab
* `Disable cache` box enable
* (But make sure the box is disabled otherwise!)

