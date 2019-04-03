#include "FM_Synth.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void FM_Synth::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst_n\" :  \"" << ap_rst_n.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"result_V_TDATA\" :  \"" << result_V_TDATA.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"result_V_TVALID\" :  \"" << result_V_TVALID.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"result_V_TREADY\" :  \"" << result_V_TREADY.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"press\" :  \"" << press.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"attackMaximum\" :  \"" << attackMaximum.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"attackDuration\" :  \"" << attackDuration.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"decayDuration\" :  \"" << decayDuration.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"sustainAmplitude\" :  \"" << sustainAmplitude.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"sustainDuration\" :  \"" << sustainDuration.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"releaseDuration\" :  \"" << releaseDuration.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_AWVALID\" :  \"" << s_axi_CTRL_BUS_AWVALID.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_axi_CTRL_BUS_AWREADY\" :  \"" << s_axi_CTRL_BUS_AWREADY.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_AWADDR\" :  \"" << s_axi_CTRL_BUS_AWADDR.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_WVALID\" :  \"" << s_axi_CTRL_BUS_WVALID.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_axi_CTRL_BUS_WREADY\" :  \"" << s_axi_CTRL_BUS_WREADY.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_WDATA\" :  \"" << s_axi_CTRL_BUS_WDATA.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_WSTRB\" :  \"" << s_axi_CTRL_BUS_WSTRB.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_ARVALID\" :  \"" << s_axi_CTRL_BUS_ARVALID.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_axi_CTRL_BUS_ARREADY\" :  \"" << s_axi_CTRL_BUS_ARREADY.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_ARADDR\" :  \"" << s_axi_CTRL_BUS_ARADDR.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_axi_CTRL_BUS_RVALID\" :  \"" << s_axi_CTRL_BUS_RVALID.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_RREADY\" :  \"" << s_axi_CTRL_BUS_RREADY.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_axi_CTRL_BUS_RDATA\" :  \"" << s_axi_CTRL_BUS_RDATA.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_axi_CTRL_BUS_RRESP\" :  \"" << s_axi_CTRL_BUS_RRESP.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_axi_CTRL_BUS_BVALID\" :  \"" << s_axi_CTRL_BUS_BVALID.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"s_axi_CTRL_BUS_BREADY\" :  \"" << s_axi_CTRL_BUS_BREADY.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_axi_CTRL_BUS_BRESP\" :  \"" << s_axi_CTRL_BUS_BRESP.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}

