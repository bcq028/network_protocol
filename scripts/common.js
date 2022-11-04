import {execSync} from 'child_process'
import path from 'path';
import {fileURLToPath} from 'url'

const __filename=fileURLToPath(import.meta.url);
const __dirname=path.dirname(__filename);

const cwd=path.resolve(__dirname,'..');

export const src_path=path.join(cwd,'src');
export const build_path=path.join(cwd,'build');
export const test_path=path.join(cwd,'tests');

export const sh=cmd=>execSync(cmd,{stdio:'inherit',cwd});



