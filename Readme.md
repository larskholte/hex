hex
===

Simple C library to translate strings to and from hexadecimal notation.

The main functions are FromHex and ToHex, which perform the transformations suggested by their names. Translation may be performed to or from uppercase or lowercase hex characters. A null character ('\0') may optionally be appended.

An advantage of this library over some others is that the translations can occur in-place. That is, the binary array and the array of hexadecimal characters may have the same starting address in memory.

License
-------

Copy and use as you please. No attribution is necessary.
