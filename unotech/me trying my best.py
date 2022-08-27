from bs4 import BeautifulSoup
import requests
import pandas as pd
import aiohttp
import asyncio
import os

name_ = []
address_ = []
number_ = []
time_ = []

async def scrape(i):
    try:
        async with aiohttp.ClientSession() as session:
            async with session.post("https://www.singhealth.com.sg/rhs/GP-Result?ClinicName=&ProgrammesAndInitiatives=&OpenHours=&Location=",data={"__EVENTTARGET": "ctl00$ctl55$g_351c148f_5ddb_4aaa_823d_23e329509409$ctl00$grvGPResult", "__EVENTARGUMENT": f"Page${i}"}) as page:   

                soup = BeautifulSoup(await page.text(),'html.parser')
                clinics = soup.find_all("td",class_="ms-vb2")
                
                for clinic in clinics:
                    NAME = clinic.div.label.text
                    print(NAME)
                    allatag = clinic.find_all("a")
                    # print(len(addresses))
                    add = []
                    for p in range (len(allatag)):
                        address=allatag[p]
                        # print(address.text)
                        add.append(address.text)
                    ADDRESS = "\n".join(add)
                        

                    allspantag=clinic.find_all("span")
                    # print(len(allspantag))
                    n = []
                    Tnumber = ""
                    Fnumber = ""
                    for j in range (len(allspantag)):
                        if "T +65" in allspantag[j].text:
                            Tnumber=allspantag[j].text
                            # print(Tnumber.text)
                            
                        if "F +65" in allspantag[j].text:
                            Fnumber=allspantag[j].text
                    
                    # print(Tnumber,Fnumber)
                    n = [Tnumber, Fnumber]
                    NUMBER = "\n".join(n)


                    t = []
                    allptag = clinic.find_all("p")
                    for k in range(len(allptag)):
                        if "##" not in allptag[k].text:
                            if "#" not in allptag[k].text:
                                if "km" not in allptag[k].text:
                                    if "Singapore" not in allptag[k].text:
                                        if address.text not in allptag[k].text:
                                            if "0" in allptag[k].text or "Open" in allptag[k].text:
                                                time=allptag[k]
                                                t.append(time.text)
                    TIME = "\n".join(t)

                    name_.append(NAME)
                    address_.append(ADDRESS)
                    number_.append(NUMBER)
                    time_.append(TIME)

    except Exception as e:
        print(e)

# namefinal=",".join(f'"{na}"' for na in name_)
# addressfinal=",".join(f'"{add}"' for add in address_)
# numberfinal=",".join(f'"{nun}"' for nun in number_)
# timefinal=",".join(f'"{ti}"' for ti in time_) 

async def final():
    task=[asyncio.create_task(scrape (i)) for i in range (281)]
    await asyncio.gather(*task)


asyncio.set_event_loop_policy(asyncio.WindowsSelectorEventLoopPolicy())
asyncio.run(final())

clinic_data={
    "name": name_, 
    "address": address_, 
    "number": number_, 
    "time": time_}

df = pd.DataFrame(clinic_data, columns = ["name", "address","number", "time"])

df.to_excel(r"C:\Users\licyn\latex\unotech\web scraping.xlsx", index = False, header=True)

