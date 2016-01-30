from datetime import datetime

print (datetime.strptime('20150501', '%Y%m%d').date() - datetime.strptime('20140601', '%Y%m%d').date()).days
