#/bin/sh
ifconfig | grep -w ether | sed 's/.ether//g' | sed 's/ //g'
