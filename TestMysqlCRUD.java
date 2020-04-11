package jdbc.mysql;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author wei.jiang
 * @since 2018/11/24
 */
public class TestMysqlCRUD {

    public static void main(String[] args) {
        Connection connection = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            connection = MysqlConnectionUtil.getInstance().getConnection();
            ps = connection.prepareStatement("SELECT * FROM t_user");
            rs = ps.executeQuery();
            if (rs != null) {
                while (rs.next()){
                    System.out.println(rs.getString(2));
                }
            }
        } catch (IOException | ClassNotFoundException | SQLException e) {
            System.out.println("操作数据库失败" + e.getMessage());
            e.printStackTrace();
        } finally {
            if (connection != null) {
                try {
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }

    }


}
