# description #
iso2opl code exposed as a node.js module
study project to learn node.js native C++ modules
by sarpt

# building #

`node-gyp --rebuild --target=7.10.0`

# using #

`const isoUtils = require('./build/Release/node_oplIsoUtils');`

# functions #

getGameId(string path, boolean isBigEndian): string - returns string containing PS2 game's ID (regional code with number e.g. SLUS_203.44 for NTSC-U Rez)
throws if:
- first argument isn't a string, second one isn't a boolean and overall if there's less than two arguments (any extra arguments ignored) 
- .iso file cannot be read 
- there's is a problem finiding SYSTEM.CNF file, suggesting that an .iso file probably isn't a proper PS2 .iso (at leat not the one that can be read by OPL) 
```
const isoUtils = require('./build/Release/node_oplIsoUtils');
const os = require('os');

let gameId = isoUtils.getGameId("E:\\iso\\Rez.iso", os.endianness() === "HE");
```

# authors #
Original iso2opl tool authors and people responsible for iso-related C functions:
jimmikaelkael - iso2opl.c
A.Lee & Nicholas Van Veen - isofs.c 

# license #
Licenced under Academic Free License version 3.0
