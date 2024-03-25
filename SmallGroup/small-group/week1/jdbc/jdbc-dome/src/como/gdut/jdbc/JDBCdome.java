package como.gdut.jdbc;

import javax.naming.Name;
import java.net.URL;
import java.sql.*;
import java.util.ArrayList;

public class JDBCdome {
    public static void main(String[] args) {

       String sql1="select * from tb_emp ;";
       ArrayList<ArrayList> name = CRUDUtils.query(sql1);
        System.out.println(name);

        String sql2 = "insert into tb_emp\n" +
                "values (?, ?, ?, ?, ?, ?, ?, ?, ?, now(), now());";
        int update = CRUDUtils.update(sql2, 17, "chenyouliang", "123456", "陈友谅", 1, "17.jpg", null, "2015-03-21", null);
        System.out.println(update);

    }

}
