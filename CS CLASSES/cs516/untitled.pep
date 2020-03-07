;Up
BR main
msg0: .ASCII
msg: .ASCII "Enter the Zip codes, two-character state codes, and state names. Enter a Zip code of -9999 to end the input.\x00"
msg2: .ASCII "Too many Zip code range records - maximum is nn\x00"
msg3: .ASCII     "nnnnn Zip Code records read\x00"
msg4: .ASCII     "Enter 1 to get the Zip code range for a state, 2 to get the state name for a Zip code, or 3 to end\x00"
msg5: .ASCII     "Response must be 1, 2, or 3 - please try again\x00"
msg6: .ASCII     "Zip code range for state xx is yyyyy through zzzzz\x00"
msg7: .ASCII     "State code xx was not found in the table\x00"
msg8: .ASCII     "Zip code xxxxx is in state yy\x00"
msg9: .ASCII     "Zip code xxxxx was not found in any state\x00"

main: 