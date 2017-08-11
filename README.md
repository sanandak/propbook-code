# Code for propeller pasm tutorial book.

Purchase the book at [Leanpub Propeller Book](https://leanpub.com/propellerassemblerpasmintroduction).

Download the SimpleIDE app from http://learn.parallax.com.
On a mac, this will install the executables in 
`/Applications/SimpleIDE.app/Contents/propeller-gcc/bin`, which should be added
to your path

```
export PROPDIR=/Applications/SimpleIDE.app/Contents/propeller-gcc/
export PATH=$PROPDIR/bin:$PATH
```

## Getting this code
You can either download the code as a zip file (see the green button above labeled "Clone or Download") or you can use git as it is intended: a source code management tool (SCM).

In order to use it as an SCM, you will need to install the `git` program or a GUI client (see http://desktop.github.com for one such).

Clone the repository (as this set of files is called):
```
git clone https://github.com/sanandak/propbook-code.git
```
This will create a directory `propbook-code` that is identical to this one.

At any later time, as I make changes to the repository, you can update
your copy:
```
git pull origin master
```


## Board configurations
If your board is not present in `$PROPDIR/propeller-load`, then copy one of the
other ones (for example `quickstart.cfg`) and edit it for your board.  The board we use here has a clock speed of 100MHz, but is otherwise the same as
the quickstart board.

Copy it to a new file and edit it.  In addition, edit the `boards.txt` file 
so that the new board appears as an option in SimpleIDE.
```
> cd $PROPDIR/propeller-load
> sudo cp quickstart.cfg psu.cfg
> vi psu.cfg
> vi boards.txt
```

```
# psu.cfg0
    clkfreq: 100000000
    clkmode: XTAL1+PLL16X
    baudrate: 115200
    rxpin: 31
    txpin: 30
    tvpin: 12   # only used if TV_DEBUG is defined
    cache-driver: eeprom_cache.dat
    cache-size: 8K
    cache-param1: 0
    cache-param2: 0
    eeprom-first: TRUE
```

## Compiling and downloading code

The directories refer to the chapters of the book.  The `libs` directory
has needed libraries (serial port, number formatting, and unit-testing).

The board configuration refers to a file in `$PROPDIR/propeller-load`, in this case `psu.cfg`.

```
> cd ch3
> openspin hello_Demo.spin # compile the spin code to binary
> propeller-load -L ../libs -b psu -t -r filename.binary # download binary file to board, and run the program, and open a terminal 
```



