.ifndef _MACRO_INC_GUARD
.internal _MACRO_INC_GUARD
.set _MACRO_INC_GUARD, 1

# A function symbol.
.macro glabel label, visibility=global
    .\visibility "\label"
    .type "\label", @function
    "\label":
        .ent "\label"
.endm

# The end of a function symbol.
.macro endlabel label
    .size "\label", . - "\label"
    .end "\label"
.endm

.macro alabel label, visibility=global
    .\visibility "\label"
    .type "\label", @function
    "\label":
        .aent "\label"
.endm

.macro ehlabel label, visibility=global
    .\visibility "\label"
    "\label":
.endm


# A label referenced by a jumptable.
.macro jlabel label, visibility=global
    .\visibility "\label"
    "\label":
.endm


# A data symbol.
.macro dlabel label, visibility=global
    .\visibility "\label"
    .type "\label", @object
    "\label":
.endm

# End of a data symbol.
.macro enddlabel label
    .size "\label", . - "\label"
.endm


.macro nonmatching label, size=1
    .global "\label\().NON_MATCHING"
    .type "\label\().NON_MATCHING", @object
    .size "\label\().NON_MATCHING", \size
    "\label\().NON_MATCHING":
.endm

.endif
