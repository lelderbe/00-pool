#/bin/sh
#id -Gn $FT_USER | tr " " ","
# | tr -d \\n
id -Gn $FT_USER | sed 's/ /,/g' | tr -d \\n
