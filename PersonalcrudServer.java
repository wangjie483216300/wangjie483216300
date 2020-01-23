package car.car.service;

import car.car.bean.PERSONAL_CENTER;
import car.car.bean.SelectUser;
import car.car.dao.PersonalDado;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class PersonalcrudServer {
    @Autowired
    PersonalDado personalDado;
    /**
     * 修改个人信息
     * @param username
     * @param age
     * @param sex
     * @param telephone
     * @param driver_license
     * @param insurance
     * @param preminum
     * @param id
     * @return
     */
    public String updateuser(String username, int age, String sex, int telephone,String driver_license, String insurance, int preminum,int id){
        personalDado.adduser(username,age,sex,telephone,driver_license,insurance,preminum,id);
        return "修改成功!";
    }

    /**
     * 查询个人信息
     * @param ID
     * @return
     */
    public SelectUser selectuser(int ID){
        return personalDado.selectuser(ID);
    }
}
