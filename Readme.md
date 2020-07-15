hex
===

Simple C library to translate strings to and from hexadecimal notation.

The main functions are FromHex and ToHex, which perform exactly the transformations suggested by their names. Translation may be performed to or from uppercase or lowercase hex characters. A null character ('\0') may optionally be appended. Functions are also provided to perform translations of single hexadecimal characters into nibbles (half-bytes) and back.

An advantage of this library over some others is that the array transformations can occur in-place. That is, the binary array and the array of hexadecimal characters may have the same starting address in memory.

See the header file for function templates.

License
-------

Copy and use as you please. No attribution is necessary.
