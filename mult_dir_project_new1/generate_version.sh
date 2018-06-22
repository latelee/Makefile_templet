# file name: generate_version.sh
# copyleft by Late Lee 2013~2018 
#!/bin/sh 

if [ $# != 4 ]
then
    FILENAME=version.h
    MAJ_VER=0
    MIN_VER=0
    RELEASE=0
else
    FILENAME=$1 # 头文件名称
    MAJ_VER=$2  # 主版本号
    MIN_VER=$3  # 次版本号
    RELEASE=$4  # 是否发布版本（决定了生成的版本号内容）
fi

VER_FILE=$FILENAME

#编译时间
GEN_DATE=`date +"build: %Y-%m-%d %k:%M:%S"`

# 读取Git版本号 
TESTGIT=`git rev-list HEAD`
if [ "$TESTGIT" != "" ]
then
    GITLOCALVER=`git rev-list HEAD --count`
    #echo "Git Local version:" $GITLOCALVER
    GIT_VER=$GITLOCALVER
    GIT_VER1="$(git rev-list HEAD -n 1 | cut -c 1-8)"
    GIT_VERSION=$GIT_VER1
    VB_HASGITVER=1
else
    echo "There is no Git version control."
    VB_HASGITVER=0
    exit
fi

#生成版本信息文件 
if [ $VB_HASGITVER = 0 ]
then
    echo "There isn't any version control."
else
    echo "#ifndef _VERSION_H_" > $VER_FILE
    echo "#define _VERSION_H_" >> $VER_FILE
    echo "" >> $VER_FILE

    if [ $VB_HASGITVER = 1 ]
    then
        BUILD_VER="[$GIT_VERSION $GEN_DATE]"
        echo "#define VER_MAJOR $MAJ_VER" >> $VER_FILE
        echo "#define VER_MINOR $MIN_VER" >> $VER_FILE
        echo "#define VER_BUILD $GIT_VER" >> $VER_FILE
        if [ $RELEASE = 1 ]
        then
            echo "#define VERSION_STRING \"v$MAJ_VER.$MIN_VER.$GIT_VER\"" >> $VER_FILE
        else
            echo "#define VER_BTIME \"$BUILD_VER\"" >> $VER_FILE
            echo "#define VERSION_STRING \"v$MAJ_VER.$MIN_VER.$GIT_VER $BUILD_VER\"" >> $VER_FILE
        fi
    fi

    echo "" >> $VER_FILE
    echo "#endif" >> $VER_FILE
fi

echo "Generate " "v$MAJ_VER.$MIN_VER.$GIT_VER $BUILD_VER"
echo "to file:" $VER_FILE