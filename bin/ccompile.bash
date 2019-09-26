#! /bin/bash
filename=$1
file_path="$(pwd)/${filename}"
gcc "${file_path}.c" -o "${file_path}" -pedantic && "${file_path}" && rm rm "${file_path}"
