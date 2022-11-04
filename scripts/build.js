import fs from 'fs'
import chalk from 'chalk'
import {sh,src_path,build_path} from './common.js'

let files=fs.readdirSync(src_path).filter(name=>name.split('.').at(-1)==='c');

let build=`gcc -g -Wall -o ${build_path}/main `;

files.forEach(filename=>build+=` ${src_path}/${filename}`);

try{
    sh(build);
}catch(err){
    console.error(chalk.red('build failed.'))
    console.log(build)
}


