read -p "Range bot : " RANGEBOT
read -p "Range top : " RANGETOP
ARG=`ruby -e "puts ($RANGEBOT..$RANGETOP).to_a.shuffle.join(' ')"`
./push_swap -s -d $ARG #| ./checker $ARG
