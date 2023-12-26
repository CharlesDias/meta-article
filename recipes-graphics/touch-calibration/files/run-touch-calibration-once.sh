#!/bin/sh
# run-touch-calibration.sh

TOUCH_DEVICE="/sys/devices/platform/soc/2100000.bus/21a4000.i2c/i2c-1/1-002c/input/input0/event0"
MAX_ATTEMPTS=5  # The number of attempts you want

# Function to run weston-touch-calibrator
run_calibration() {
    weston-touch-calibrator $TOUCH_DEVICE
    return $?
}

attempt=0
success=0

while [ $attempt -lt $MAX_ATTEMPTS ]; do
    echo "Attempting touch calibration: Attempt $((attempt + 1))/$MAX_ATTEMPTS"
    run_calibration
    if [ $? -eq 0 ]; then
        echo "Touch calibration successful."
        success=1
        break
    else
        echo "Touch calibration failed, retrying..."
    fi
    attempt=$((attempt + 1))

    # Sleep for 2 second before retrying
    sleep 2
done

if [ $success -eq 0 ]; then
    echo "Touch calibration failed after $MAX_ATTEMPTS attempts."
    echo "This service will run again on the next boot."
else
    echo "Touch calibration succeeded after $((attempt + 1)) attempts."

    echo "Disable this service so it doesn't run on subsequent boots"
    systemctl disable run-touch-calibration-once.service
fi
