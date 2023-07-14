/* startup bashar */

.section .vectors
.word 0x20001000
.word reset
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler

.section .text
reset:
bl main
b .

.thumb_func
vector_handler:
b reset



