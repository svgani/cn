BEGIN{
count1=0
pack1=0
time1=0
}
{
if($1=="r" && $3=="_5_" && $4=="AGT")
{
count1++
pack1=pack1+$8
time1=$2
}
}
END{
printf("The Throughput from n5 to n6: %f Mbps \n", ((count1*pack1*8)/(time1*1000000)));
}
