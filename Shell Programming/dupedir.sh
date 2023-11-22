#! /usr/bin/bash 
source="$1"
dest="$2"

cp -R $source $dest
chmod -R 764 $dest

storeInfo(){
    local dir="$1"
    ls -l "$dir" >> "$dir/directoryInfo.txt"
    ls "$dir" | while read item
    do 
        if [ -d "$dir/$item" ]
        then 
            storeInfo "$dir/$item"
        fi
    done
}

storeInfo $dest





