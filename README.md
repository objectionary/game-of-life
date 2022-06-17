# John Conway's Game of Life 

<img src="https://play-lh.googleusercontent.com/4xtboOCl4G36He2_RUaYhI9v_eDIoXara2hAxDi99f1R5MwLjSI1QZ_CT6wLdjCTV3E" width="200" height="200" />

![badge](	https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/potatmen/Life/blob/master/LICENSE.txt)
[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

This project aims to show that [John Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) written in C++ using OOP features (inheritance, encapsulation, polymorphism) works slower than the same realization using [EO programming language](https://github.com/objectionary/eo), the more general aim is to show that using EO language is more benifitial for projects that use many objects in terms of exection time.


## Table of Contents

- [Background](#background)
- [Install](#install)
- [Realization](#structure)
- [Usage](#usage)

## Background

According to [previous research](https://github.com/yegor256/fibonacci) measurements showed that C++ realization to count Fibonacci numbers using objects work slowly, therefore, we decided to implement Game of Life. Fibonacci number counting is not sufficient enough because using objects for it's realization is something pulled out of a hat, because we can use a simple loop to count it.
    
## Install


## Structure

![Code structure](https://user-images.githubusercontent.com/90863441/174275386-16798ab9-4833-4d6b-9e5e-7bf01a39e91a.png)

Here is the structure of objects. The ususal line means inheritance and goes from parent to child, the dotted line means that some object uses other object as an attribute. As you can see, object Grid uses object Cell. More details will be provided in next sections.

## Usage
