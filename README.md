# WLCIProject [![Build Status](https://travis-ci.org/alexeybondarenko/WLCIProject.svg?branch=master)](https://travis-ci.org/alexeybondarenko/WLCIProject)

Project with implimentation of CI fow Worklight hyprid app project.

## Installation

### Configure environment

To start working wsith project, you should have installed:

- grunt-cli
- compass
- bower

If you need to install then, execude command below in command line:
	
	npm install -g grunt-cli compass bower

### Pre-build project


	cd apps/CIProject/sources/ # go to source folder
	npm install # install npm dependencies from package.json
	bower install # install project web dependenciess from bower.json

### Build project

Building project consist from 2 step: 
- build HTML5 project
- build IBM Mobile First project.

Buildin HTML5 project: application from `sources/app` copying to `common/` folder and all files are minifying and concat.

Building IBM Mobile First project: sources from `common/` folder insert to environments folders (eg., iphone, android folders). At the finish of this step you should have `.wlapp` file to deploy on Worklight Server. 

### Licence