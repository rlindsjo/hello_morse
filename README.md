# hello_morse

Make arduino blink a hardcoded message using morse. Have a gifte arduino send a personalised message on startup.

Only send a-z, all other characters are interpreted as space.

The characters are binary encoded bit dot as 0 and dash as 1, with one high stop bit. Eg.

> a -> 5 (**1**01)
> m -> 7 (**1**11)
> x -> 25 (**1**1001)

