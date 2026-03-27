# Protocol
---
1.Right Now only works: SET (L/M/H) (DEGREES)
2.There are more commands but they are not implemented yet: "GET" "PING" "RESET"
Example:
```txt
SET L 45  
SET M 20  
SET H 0
```
sending a command from Client-Debug: "SET M 45/n"
"/n" is really important, because it says to the server THAT is the final of the message.
