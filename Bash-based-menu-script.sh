#!/bin/bash
#set -x
clear

#Display CPU info
option1() 
{
    echo Option 1 Selected
    cat /proc/cpuinfo
    echo
}

#Display Sys Interrupts
option2() 
{
    echo Option 2 Selected
    cat /proc/interrupts | grep 'interrupts'
    echo
}

#Display output devices and number of megabits read
option3() 
{
    echo Option 3 Selected
    awk '{print $3,"\t\t",$4;}' /proc/diskstats | grep -v "loop"
    echo
}

#Display a process's PID and status
option4() 
{
    echo Option 4 Selected
    
    echo
}

#While loop exit variable
exit_menu=false
 
#menu
while [ "${exit_menu}" == false ]
do     
    #List options
    echo Information Menu for Advanced Task Lab 5
    echo 
    echo 1. Display CPU info
    echo 2. Display Sys Interrupts
    echo 3. Display Output Device names and Number of megabits read
    echo 4. Display PID and status of a running process.
    echo 5. Exit menu.
    echo Enter Selection: 
    
    #Get user's input
    read choice
    echo 
    echo ----------------------------------------------------------
    echo #blank line
    #choose the user's input option and call the relevant function
    case ${choice} in 
        1) option1
        ;;
        2) option2
        ;;
        3) option3
        ;;
        4) option4
        ;;
        5) exit_menu=true
    echo Exiting...
        ;;
    esac
done


