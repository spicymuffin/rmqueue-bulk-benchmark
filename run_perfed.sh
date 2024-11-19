program_name="benchmark"

current_dir=$(pwd)
reports_dir="reports"
mkdir -p "$reports_dir"

sudo perf record -g \
    -e LLC-load-misses:k \
    -F 10000 \
    -o "${current_dir}/${reports_dir}/report.data" "./${program_name}"
