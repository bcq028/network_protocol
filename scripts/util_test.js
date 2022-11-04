import chalk from 'chalk'
import {sh,test_path,build_path, src_path} from './common.js'


let build=`gcc -g -Wall -o ${build_path}/test ${test_path}/util.test.c\
 ${src_path}/utils.h ${src_path}/utils.c
`;



try{
    sh(build);
}catch(err){
    console.error(chalk.red('test fail build failed.'))
    console.log(build)
}


