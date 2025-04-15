.macro glabel label
    .global "\label"
    .type "\label", @function
    "\label":
.endm

.macro endlabel label
.endm

.macro alabel label
    .global "\label"
    "\label":
.endm

.macro dlabel label
    .global "\label"
    "\label":
.endm

.macro jlabel label
    .global "\label"
    "\label":
.endm

.macro ehlabel label, visibility=global
    .\visibility "\label"
    "\label":
.endm
