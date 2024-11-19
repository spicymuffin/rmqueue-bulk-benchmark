program_name="benchmark"

current_dir=$(pwd)
traces_dir="traces"
mkdir -p "$traces_dir"

sudo bpftrace -c "./${program_name}" rmqueue_tracer.bt > "${current_dir}/${traces_dir}/trace.log"